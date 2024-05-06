import 'dart:collection';
import 'dart:math';

import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';
import 'package:provider/provider.dart';

class ShoppingApp extends StatelessWidget {
  const ShoppingApp({super.key});

  @override
  Widget build(BuildContext context) {
    return ChangeNotifierProvider(
      create: (context) => CartModel(),
      child: const MyApp(
        scaffold: ShoppingView(),
      ),
    );
  }

  static const name = 'Shopping';
}

class ShoppingView extends StatefulWidget {
  const ShoppingView({super.key});

  @override
  State<StatefulWidget> createState() => _ShoppingViewState();
}

class _ShoppingViewState extends State<ShoppingView> {
  var items = Catalog.generateItems();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text(ShoppingApp.name),
        actions: [
          IconButton(
            icon: const Icon(Icons.shopping_cart),
            onPressed: () {
              Navigator.push(
                context,
                MaterialPageRoute(
                  builder: (context) => const CartView(),
                ),
              );
            },
          ),
        ],
      ),
      drawer: myDrawer,
      body: Padding(
        padding: const EdgeInsets.all(10),
        child: _buildCatalogItems(context),
      ),
    );
  }

  Widget _buildCatalogItems(BuildContext context) {
    return Consumer<CartModel>(
      builder: (context, cart, child) => ListView.builder(
        itemCount: items.length,
        itemBuilder: (context, index) => ListTile(
          leading: AspectRatio(
            aspectRatio: 1,
            child: Container(
              color: items[index].color,
            ),
          ),
          title: Text(items[index].name),
          subtitle: Text('\$${items[index].price}'),
          trailing: cart.items.contains(items[index])
              ? IconButton(
                  icon: const Icon(
                    Icons.remove_circle,
                    color: Colors.red,
                  ),
                  onPressed: () {
                    cart.remove(items[index]);
                  },
                )
              : IconButton(
                  icon: const Icon(
                    Icons.add_circle,
                    color: Colors.green,
                  ),
                  onPressed: () {
                    cart.add(items[index]);
                  },
                ),
        ),
      ),
    );
  }
}

class CartView extends StatelessWidget {
  const CartView({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Cart'),
      ),
      body: Padding(
        padding: const EdgeInsets.all(10),
        child: Consumer<CartModel>(
          builder: (context, cart, child) => Column(
            children: [
              ListTile(
                leading: const Icon(Icons.summarize),
                title: Text('Total: \$${cart.totalPrice}'),
              ),
              ...cart.items.map(
                (item) => ListTile(
                  leading: AspectRatio(
                    aspectRatio: 1,
                    child: Container(
                      color: item.color,
                    ),
                  ),
                  title: Text(item.name),
                  subtitle: Text('\$${item.price}'),
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}

@immutable
class Item {
  final int id;
  final String name;
  final Color color;
  final int price;

  Item(this.id, this.name, this.price)
      : color = Colors.primaries[id % Colors.primaries.length];

  @override
  int get hashCode => id;

  @override
  bool operator ==(Object other) =>
      other is Item && other.id == id && other.price == price;
}

class Catalog {
  static final itemNames = ['one', 'two', 'three', 'four', 'five'];
  static List<Item> generateItems() {
    var rand = Random(42);
    return itemNames.indexed
        .map(
          (e) => Item(
            e.$1,
            e.$2,
            rand.nextInt(200) + 19,
          ),
        )
        .toList();
  }
}

class CartModel extends ChangeNotifier {
  final List<Item> _items = [];
  List<Item> get items => _items;
  int get totalPrice => _items.map((e) => e.price).fold(0, (a, b) => a + b);

  void add(Item item) {
    _items.add(item);
    notifyListeners();
  }

  void remove(Item item) {
    _items.remove(item);
    notifyListeners();
  }
}
