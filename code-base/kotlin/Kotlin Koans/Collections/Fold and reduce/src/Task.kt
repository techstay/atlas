// Return the set of products that were ordered by all customers
fun Shop.getProductsOrderedByAll(): Set<Product> =
    customers.map { it.getOrderedProducts() }
        .reduce { acc, products -> acc.intersect(products) }

fun Customer.getOrderedProducts(): Set<Product> =
    orders.flatMap { it.products }.toSet()
