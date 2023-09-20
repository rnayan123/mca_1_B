const productList = document.getElementById("productList");
const searchInput = document.getElementById("searchInput");
const sortSelect = document.getElementById("sortSelect");

function fetchProducts() {
  fetch("https://cynthiaesthermetilda.github.io/Xhrdemo/products.json")
    .then((response) => {
      if (!response.ok) {
        throw new Error("Failed to fetch products.");
      }
      return response.json();
    })
    .then((products) => {
      displayProducts(products);
    })
    .catch((error) => {
      console.error(error);
    });
}

function displayProducts(products) {
  productList.innerHTML = "";

  const sortBy = sortSelect.value;
  products.sort((a, b) => {
    if (sortBy === "name") {
      return a.name.localeCompare(b.name);
    } else if (sortBy === "price") {
      return a.price - b.price;
    }
  });

  const filterText = searchInput.value.toLowerCase();
  const filteredProducts = products.filter((product) => {
    return (
      product.name.toLowerCase().includes(filterText) ||
      product.description.toLowerCase().includes(filterText)
    );
  });

  filteredProducts.forEach((product) => {
    const productDiv = document.createElement("div");
    productDiv.className = "product";

    const productImage = document.createElement("img");
    productImage.src = product.image;
    productImage.alt = product.name;

    const productName = document.createElement("h2");
    productName.textContent = product.name;

    const productDescription = document.createElement("p");
    productDescription.textContent = product.description;

    const productPrice = document.createElement("p");
    productPrice.textContent = `$${product.price.toFixed(2)}`;

    productDiv.appendChild(productImage);
    productDiv.appendChild(productName);
    productDiv.appendChild(productDescription);
    productDiv.appendChild(productPrice);

    productList.appendChild(productDiv);
  });
}

searchInput.addEventListener("input", fetchProducts);
sortSelect.addEventListener("change", fetchProducts);

fetchProducts();