document.addEventListener("DOMContentLoaded", function () {
    const fetchBooksButton = document.getElementById("fetchBooks");
    const bookList = document.getElementById("bookList");


    fetchBooksButton.addEventListener("click", function () {
        const apiUrl = "https://books-api-rz6d.onrender.com/books"; 

        fetch(apiUrl)
            .then(response => {
                if (!response.ok) {
                    throw new Error(`Network response was not ok (Status: ${response.status})`);
                }
                return response.json();
            })
            .then(booksData => {
                displayBooks(booksData);
            })
            .catch(error => {
                console.error("Error fetching data:", error);
            });
    });

    // Function to display the list of books
    function displayBooks(booksData) {
        bookList.innerHTML = "";

        const  ol=document.createElement("ol");

        booksData.forEach(function (book) {
            const li = document.createElement("li");
            li.textContent = `${book.author} lives in ${book.country} has written a book of title ${book.tile} in ${book.language} language` ;
            
            ol.appendChild(li)
        
        });

    
        bookList.appendChild(ol);
    
    }
});
