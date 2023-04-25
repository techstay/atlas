package yitian.study.skilled

fun main(args: Array<String>) {

    //获取订单数最多的顾客
    val customerOfMaxOrder = orders().groupBy { it.customer }
            .maxBy { it.value.size }
            ?.key
    println("获取订单数最多的顾客:$customerOfMaxOrder")

    //获取订单金额最多的顾客
    val customerOfMaxOrderPrice = orders().groupBy { it.customer }
            .maxBy { it.value.sumByDouble { it.products.sumByDouble { it.price } } }
            ?.key
    println("获取订单金额最多的顾客:$customerOfMaxOrderPrice")

    //价格最贵的商品
    val mostExpensiveProduct = products().maxBy { it.price }
    println("价格最贵的商品:$mostExpensiveProduct")

    //计算机类的所有商品
    val productsOfComputer = products().filter { it.category == Category.Computer }
    println("计算机类的所有商品:$productsOfComputer")

    //最便宜的三件商品
    val productsOfCheapestThree = products().sortedBy { it.price }
            .filterIndexed({ index, _ -> index < 3 })
    println("最便宜的三件商品:$productsOfCheapestThree")

    //每个顾客购买的商品列表
    val productsOfCustomers = orders().groupBy { it.customer }
            .map { it.value.map { it.products }.flatten() }
    //每位顾客都购买了的商品
    val productsOfEveryCustomer = productsOfCustomers.fold(products(), {
        result, products ->
        result.intersect(products).toList()
    })
    println("每位顾客都购买了的商品:$productsOfEveryCustomer")
}

data class Product(val name: String, val price: Double, val category: Category)
data class City(val name: String)
data class Customer(val name: String, val city: City) {
    override fun toString(): String {
        return "Customer(name=$name, city=$city)"
    }
}

data class Order(val products: List<Product>, val customer: Customer)
enum class Category {
    Computer, Education, Game
}

fun cities(): List<City> {
    return listOf(City("呼和浩特")
            , City("北京")
            , City("上海")
            , City("天津")
            , City("武汉"))
}

fun products(): List<Product> {
    return listOf(Product("Intel Core i7-7700k", 2799.00, Category.Computer),
            Product("AMD Ryzen 7 1700", 2499.0, Category.Computer),
            Product("Counter Strike", 10.0, Category.Game),
            Product("Batman", 79.0, Category.Game),
            Product("Thinking in Java", 59.0, Category.Education),
            Product("C# Programming", 99.0, Category.Education)
    )
}

fun customers(): List<Customer> {
    return listOf(Customer("易天", cities()[0])
            , Customer("张三", cities()[1])
            , Customer("李四", cities()[2])
            , Customer("沪生", cities()[3])
            , Customer("王五", cities()[4]))
}

fun orders(): List<Order> {
    return listOf(Order(products().subList(0, 3), customers()[0])
            , Order(products().subList(3, products().size), customers()[0])
            , Order(products().subList(1, 3), customers()[1])
            , Order(products().subList(2, 4), customers()[2])
            , Order(products().subList(0, 4), customers()[3])
            , Order(products().subList(1, 5), customers()[4])
    )
}