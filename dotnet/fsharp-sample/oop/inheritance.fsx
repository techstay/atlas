type Employee(name: string, age: int) =
  member this.name = name
  member this.age = age
  // abstract properties
  abstract Salary: float with get
  default this.Salary = 1800

  override this.ToString() =
    $"Employee({name},{age}) with salary {this.Salary}"

type Manager(name, age) =
  inherit Employee(name, age)
  let coefficient = 2
  override x.Salary = float (coefficient) * base.Salary

let employee = new Employee("jack", 18)
let manager = new Manager("techstay", 19)
