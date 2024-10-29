# bst-city-data-management
# Binary Search Tree Implementation for City Data Management

## Overview

This project involves the implementation of a balanced **Binary Search Tree (BST)** in C for managing a global city dataset. Developed in association with the Lebanese University from April 2021 to June 2021, the application efficiently handles large datasets by optimizing key operations to enhance data query speeds.

## Features

- **Balanced Binary Search Tree**: Ensures optimal operation times by maintaining the tree's balance for efficient data retrieval.
- **Data Management**: Manages a comprehensive global city dataset sourced from a CSV file.
- **Optimized Operations**:
  - **Insertion, Deletion, Search**: Enhanced to improve data query speeds by at least 30%.
- **User Interface**:
  - **Command-Line Interface (CLI)**: Facilitates efficient reading and updating of the dataset, with multiple data retrieval options.

### Functionalities

- **Print Largest Cities**: `printLargest10` displays the 10 largest cities by population with information including name, latitude, longitude, country, and population.
- **Print Smallest Cities**: `printSmallest10` lists the 10 smallest cities by population.
- **Print Cities by Country**: `printCountry` accepts a country name as input and prints all cities in that country.
- **Print Closest Cities**: `printClosest10` receives latitude and longitude as input and lists the 10 cities closest to these coordinates, using the Haversine formula to compute distances.
- **Additional Functionalities**:
  - Suggested extra functions may include options like displaying the largest cities within a given country or similar queries.
- **Data Persistence**: Data can be stored in a file where cities are sorted by population size.

## Technologies Used

- **Programming Language**: C
- **Data Format**: CSV for dataset storage
- **Version Control**: Git & GitHub

## Installation

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/your-username/bst-city-data-management.git
    ```

2. **Navigate to the Project Directory**:
    ```bash
    cd bst-city-data-management
    ```

3. **Compile the Code**:
    ```bash
    gcc -o bst main.c bst.c
    ```

4. **Run the Application**:
    ```bash
    ./bst
    ```

## Usage

Upon running the application, you can perform the following operations:

- **Insert a City**: Add a new city to the dataset.
- **Delete a City**: Remove an existing city from the dataset.
- **Search for a City**: Retrieve information about a specific city.
- **Update Dataset**: Modify existing city data.
- **Print Largest Cities**: Use `printLargest10` to display the 10 largest cities.
- **Print Smallest Cities**: Use `printSmallest10` to display the 10 smallest cities.
- **Print Cities by Country**: Enter a country name to display all cities within it.
- **Print Closest Cities**: Provide latitude and longitude to display the 10 closest cities.

### Command-Line Interface Options

When prompted, enter:
- **1** to print the 10 largest cities.
- **2** to print the 10 smallest cities.
- **3** to enter a country name and print all cities from that country.
- **4** to enter latitude and longitude and print the 10 closest cities.
- **quit** to exit the application.


## Team Members

- **Batool Kassem**
- **Nisreen Hamze**
- **Manar Shehazi**

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgements

- **Lebanese University** for providing the platform, resources, and comprehensive city data.
