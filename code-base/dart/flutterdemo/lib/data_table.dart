import 'package:faker/faker.dart';
import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class DataTableApp extends StatefulWidget {
  const DataTableApp({super.key});
  static const name = 'Data Table';

  @override
  State<DataTableApp> createState() => _DataTableAppState();
}

class _DataTableAppState extends State<DataTableApp> {
  final _data = List.generate(20, (index) => Person.random());
  int? _sortColumnIndex;
  var _sortAscending = true;

  @override
  Widget build(BuildContext context) {
    return MyScaffoldApp(
      navName: DataTableApp.name,
      view: SingleChildScrollView(
        child: DataTable(
          sortColumnIndex: _sortColumnIndex,
          sortAscending: _sortAscending,
          columns: [
            DataColumn(
              label: const Text('Name'),
              onSort: _onSortColumn,
            ),
            DataColumn(
              label: const Text('Age'),
              numeric: true,
              onSort: _onSortColumn,
            ),
            DataColumn(
              label: const Text('Job'),
              onSort: _onSortColumn,
            ),
          ],
          rows: _data
              .map((e) => DataRow(
                    cells: [
                      DataCell(Text(e.name)),
                      DataCell(Text(e.age.toString())),
                      DataCell(Text(e.job)),
                    ],
                  ))
              .toList(),
        ),
      ),
    );
  }

  void _onSortColumn(int columnIndex, bool sortAscending) {
    _sortColumnIndex = columnIndex;
    _sortAscending = sortAscending;
    setState(() {
      return switch (columnIndex) {
        0 => sortAscending
            ? _data.sort((a, b) => a.name.compareTo(b.name))
            : _data.sort((b, a) => a.name.compareTo(b.name)),
        1 => sortAscending
            ? _data.sort((a, b) => a.age.compareTo(b.age))
            : _data.sort((b, a) => a.age.compareTo(b.age)),
        _ => sortAscending
            ? _data.sort((a, b) => a.job.compareTo(b.job))
            : _data.sort((b, a) => a.job.compareTo(b.job)),
      };
    });
  }
}

class Person {
  Person({
    required this.name,
    required this.age,
    required this.job,
  });

  final String name;
  final int age;
  final String job;

  static final _faker = Faker.withGenerator(RandomGenerator(seed: 42));

  Person.random()
      : name = _faker.person.name(),
        age = _faker.randomGenerator.integer(100, min: 0),
        job = _faker.job.title();
}
