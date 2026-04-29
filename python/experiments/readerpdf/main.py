try:
    from pypdf import PdfReader
except ImportError as error:
    print(error)


pdf_pages: list[str] = []
_file_name = input("PDF to scan: ")
try:
    reader = PdfReader(_file_name)
    for i in range(len(reader.pages)):
        page = reader.pages[i]
        text = page.extract_text()
        pdf_pages.append(text)
except Exception as error:
    print(error)


try:
    with open("output.txt", "w") as f:
        for _page in pdf_pages:
            f.write(_page)
except Exception as error:
    print(error)
