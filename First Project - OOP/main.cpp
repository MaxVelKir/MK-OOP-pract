#include <iostream>
#include <cstring>
#include <fstream>

#include "Room.h"
#include "Hotel.h"
#include "Date.h"

using namespace std;

const int MAX_L_M = 100;

bool isWord(char c) {
    return (c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9') ||
           c == '_';
}

int wordCount(const char* text) {
    int count = 0;
    while(*text) {
        while(*text && !isWord(*text))
            text++;
        if(*text)
            count++;
        while(isWord(*text))
            text++;
    }
    return count;
}

void extractWords(const char* text, char *** wordsPtr) {
    int count = wordCount(text);
    *wordsPtr = new(nothrow) char*[count];

    for (int i = 0; i < count; ++i) {
        while (*text && !isWord(*text))
            ++text;
        if (*text) {
            const char* start = text;
            while (isWord(*text))
                ++text;

            int len = text - start;
            (*wordsPtr)[i] = new(nothrow) char[len+1];

            for (int pos = 0; pos < len; ++pos)
                (*wordsPtr)[i][pos] = start[pos];
            (*wordsPtr)[i][len] = '\0';
        }
    }
}

void checkIn(Hotel &hotel, int count, char ** words) {
    if(count < 8)
        cerr << "Invalid entry." << endl;
    else {
        Date In(stoi(words[2]), stoi(words[3]), stoi(words[4])), Out(stoi(words[5]), stoi(words[6]), stoi(words[7]));
        if(count == 8)
            hotel.checkInRoom(stoi(words[1]), In, Out);
        else {
            int len = 0;
            for (int i = 8; i < count; ++i) {
                len += strlen(words[i]);
            }
            char* note = new char[len + 1];
            strcpy(note, words[8]);
            if(count > 9) {
                for (int i = 9; i < count; ++i) {
                    strcat(note, " ");
                    strcat(note, words[i]);
                }
            }
            hotel.checkInRoom(stoi(words[1]), In, Out, note);
        }
    }
}

void checkOut(Hotel &hotel, int count, char ** words) {
    if(count != 2)
        cerr << "You didn't enter a number" << endl;
    else
        hotel.checkOutRoom(stoi(words[1]));
}

void getAvailableRooms(Hotel &hotel, int count, char ** words) {
    if(count != 4 && count != 1)
        cerr << "Invalid entry." << endl;
    else {
        Date dt;
        switch (count) {
            case 1: dt.setDate(2020, 4, 26);
                break;
            case 4: dt.setDate(stoi(words[1]), stoi(words[2]), stoi(words[3]));
                break;

        }
        cout << "Rooms: ";
        for (int i = 0; i < hotel.getCurr(); ++i) {
            if (hotel[i].Availability(dt))
                cout << hotel[i].getNumber() << ' ';
        }
        cout << "are available." << endl;
    }
}

int counterForDays(Date &In, Date &Out) {
    int counter = 0;
    while(!(In == Out)) {
        In.setDatePlusPlus();
        counter++;
    }
    return counter;
}

//Тук дните, които отпечатва ще се разминават защото не съм имплементирал дълги и кратки месеци, февруари и високосните години
void report(Hotel &hotel, int count, char ** words) {
    if(count != 7)
        cerr << "Invalid entry." << endl;
    else {
        Date In(stoi(words[1]), stoi(words[2]), stoi(words[3])), Out(stoi(words[4]), stoi(words[5]), stoi(words[6])), Test;
        if (In > Out) {
            Date temp;
            temp = In;
            In = Out;
            Out = temp;
        }

        for (int i = 0; i < hotel.getCurr(); ++i) {
            if (!(hotel[i].getIn() == Test) && !(hotel[i].getOut() == Test)) {
                if ((hotel[i].getIn() == In && Out < hotel[i].getOut()) ||
                    (hotel[i].getIn() == In && hotel[i].getOut() == Out) ||
                    (In > hotel[i].getIn() && Out == hotel[i].getOut() ||
                     (In > hotel[i].getIn() && Out < hotel[i].getOut())))
                    cout << hotel[i].getNumber() << " - " << counterForDays(In, Out) << " days." << endl;
                else if ((In < hotel[i].getIn() && Out < hotel[i].getOut()) ||
                         (In < hotel[i].getIn() && hotel[i].getOut() == Out))
                    cout << hotel[i].getNumber() << " - " << counterForDays(hotel[i].getIn(), Out) << " days." << endl;
                else if ((hotel[i].getIn() == In && Out > hotel[i].getOut()) ||
                         (In > hotel[i].getIn() && Out > hotel[i].getOut()))
                    cout << hotel[i].getNumber() << " - " << counterForDays(In, hotel[i].getOut()) << " days." << endl;
                else if (In < hotel[i].getIn() && Out > hotel[i].getOut())
                    cout << hotel[i].getNumber() << " - " << counterForDays(hotel[i].getIn(), hotel[i].getOut())
                         << " days." << endl;
            }
        }
    }
}

void findBeds(Hotel &hotel, int count, char ** words) {
    if(count != 8)
        cerr << "Invalid entry." << endl;
    else {
        Date In(stoi(words[2]), stoi(words[3]), stoi(words[4])), Out(stoi(words[5]), stoi(words[6]), stoi(words[7]));
        int beds = stoi(words[1]);

        int arr[hotel.getCurr()];
        int counter = 0;
        for (int i = 0; i < hotel.getCurr(); ++i) {
            if (In > hotel[i].getOut() && hotel[i].getBeds() >= beds) {
                arr[counter++] = hotel[i].getNumber();
            } else if (hotel[i].getIn() > Out && hotel[i].getBeds() >= beds) {
                arr[counter++] = hotel[i].getNumber();
            }
        }

        int min = 6;
        int bestRoom;
        for (int i = 0; i < counter; ++i) {
            for (int j = 0; j < hotel.getCurr(); ++j) {
                if (arr[i] == hotel[j].getNumber()) {
                    if (hotel[j].getBeds() <= min) {
                        min = hotel[j].getBeds();
                        bestRoom = hotel[j].getNumber();
                        break;
                    }
                }
            }
        }

        if (counter == 0)
            cout << "No available rooms!" << endl;
        else
            cout << "Room number " << bestRoom << " is available." << endl;
    }

}

void unavailable(Hotel &hotel, int count, char ** words) {
    if(count < 9)
        cerr << "Invalid entry." << endl;
    else {
        int room = stoi(words[1]);
        Date In(stoi(words[2]), stoi(words[3]), stoi(words[4])), Out(stoi(words[5]), stoi(words[6]), stoi(words[7]));

        int len = 0;
        for (int i = 8; i < count; ++i) {
            len += strlen(words[i]);
        }
        char* note = new char[len + 1];
        strcpy(note, words[8]);
        if(count > 9) {
            for (int i = 9; i < count; ++i) {
                strcat(note, " ");
                strcat(note, words[i]);
            }
        }

        hotel.getExactRoom(room).getIn() = In;
        hotel.getExactRoom(room).getOut() = Out;
        hotel.getExactRoom(room).setNote(note);
    }
}

void help() {
    cout << "To check in a room : {checkin <room> <from> <to> [<note>]}" << '\n'
         << "To get availability of rooms: {availability [<date>]" << '\n'
         << "To check out a room: {checkout <room>}" << '\n'
         << "To get a report of used rooms in a time period : {report <from> <to>}" << '\n'
         << "To find optimal room : {find <beds> <from> <to>}" << '\n'
         << "To mark a room as unusable : {unavailable <room> <from> <to> <note>}" << '\n';

}

int main() {
    Hotel hotel;

    fstream file_in("rooms.txt", std::ios::in);

    int n;
    file_in >> n;

    for (int i = 0; i < n; ++i) {
        int number, beds;
        file_in >> number;
        file_in >> beds;
        Room temp(number, beds);
        hotel.addRoom(temp);
    }

    file_in.close();

    while(true) {
        char text[MAX_L_M];
        char ** words;
        cin.getline(text, MAX_L_M);
        extractWords(text, &words);
        int count = wordCount(text);

        if(count > 0) {
            if (strcmp(words[0], "checkin") == 0)
                checkIn(hotel, count, words);
            else if (strcmp(words[0], "availability") == 0)
                getAvailableRooms(hotel, count, words);
            else if (strcmp(words[0], "checkout") == 0)
                checkOut(hotel, count, words);
            else if (strcmp(words[0], "find") == 0)
                findBeds(hotel, count, words);
            else if (strcmp(words[0], "report") == 0)
                report(hotel, count, words);
            else if (strcmp(words[0], "unavailable") == 0)
                unavailable(hotel, count, words);
            else if (strcmp(words[0], "print") == 0)
                cout << hotel;
            else if (strcmp(words[0], "save") == 0)
                hotel.save();
            else if(strcmp(words[0], "help") == 0)
                help();
            else if(strcmp(words[0], "exit") == 0)
                break;
        }
    }
}
