<?xml version="1.0" encoding="UTF-8"?>
<!-- transform.xsl -->
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <!-- Match the root element -->
  <xsl:template match="/products">
    <html>
      
      <body>
        <table border="1" >
          <tr>
            <th>id</th>
            <th>name</th>
            <th>price</th>
            <th>description</th>
          </tr>
          <!-- Apply the transformation to each record -->
          <xsl:apply-templates select="product" />
        </table>
      </body>
    </html>
  </xsl:template>

  <!-- Match each record element -->
  <xsl:template match="product">
    <tr>
      <td><xsl:value-of select="id" /></td>
      <td><xsl:value-of select="name" /></td>
      <td><xsl:value-of select="price" /></td>
      <td><xsl:value-of select="description" /></td>
    </tr>
  </xsl:template>

</xsl:stylesheet>
