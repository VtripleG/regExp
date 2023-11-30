import re
def remove(input_string):
    pattern = r'\bi\w+g\b'

    result_string, count = re.subn(pattern, '', input_string)

    return result_string, count


# Пример использования
with open ('./text.txt', 'r', encoding='utf8') as file:
    input_text = file.read()

outText, count = remove(input_text)

print("Modified String:", outText)
print("Number of Removed Words:", count)
