from lxml import etree

# Transform XML to HTML
transform = etree.XSLT(etree.parse("product.xsl"))
html_output = transform(etree.parse("product.xml"))

with open("output.html", "wb") as f:
    f.write(etree.tostring(html_output, pretty_print=True))

# Validate transformed HTML against XML Schema
schema = etree.XMLSchema(etree.parse("product.xsd"))
parsed_html = etree.parse("output.html")

if schema.validate(parsed_html):
    print("Validation successful.")

else:
    print("Validation errors:")
    for error in schema.error_log:
        print(error)


