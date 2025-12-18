import locale

locale_info = locale.getlocale()
print(locale_info)
print(locale.normalize(locale_info[0] if locale_info[0] else ""))
print(locale.getencoding())
