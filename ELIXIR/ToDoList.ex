defmodule ToDoList do

end

defmodule ToDoList.CsvImporter do
  #to split into date and title?
  def import1(path) do
    temp = {}
    temp = File.stream!(path)
    |> Stream.map(&String.replace(&1, "\n", ""))
    |> Stream.map(&String.split(&1, ","))
    |> Enum.each(&Enum.each(&1, fn x -> IO.inspect(x) end))
    #Ето тук не знам накъде вече
    #|> Enum.each(&Tuple.append(temp, &1))
  end
  #to split everything individually?
  def import2(path) do
    temp = {}
    temp = File.stream!(path)
    |> Stream.map(&String.replace(&1, "\n", ""))
    |> Stream.map(&String.split(&1, ["/", ","]))
    |> Enum.each(&Enum.each(&1, fn x -> IO.inspect(x) end))
    #Ето тук не знам накъде вече
    #|> Enum.each(&Tuple.append(temp, &1))
  end
end

defmodule MultiDict do
  def new(), do: %{}

  def add(dict, key, value) do
    Map.update(dict, key, value, &[value | &1])
  end

  def get(dict, key), do: Map.get(dict, key, [])
end
