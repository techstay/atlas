(
    date now |
    date format '%Y %m %d' |
    parse "{year} {month} {day}" |
    get year
)
