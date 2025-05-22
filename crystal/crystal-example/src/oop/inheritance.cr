require "./person"

class Employee < Person
  def initialize(name : String, age : Int32, salary : Int32)
    super(name, age)
    @salary = salary
  end

  def salary
    @salary
  end
end

employee = Employee.new("John", 25, 1000)
p! employee.name
p! employee.age
p! employee.salary
