<h1 style="text-align: center">CPlusMap</h1>
<div style="text-align: center"> 

![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=white)
![Markdown](https://img.shields.io/badge/markdown-%23000000.svg?style=for-the-badge&logo=markdown&logoColor=white)
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)

</div>
<h4>Just a simple port scanner who scan every port from 1 to 65535</h4> 

<h3>📖 • TODO</h3>

---

* Do an output system
* Some optimization to gain speed
* Code the IPv4 check function
* Code a stealth TCP 
* Show the service open generaly on this port 
* Create a make file
* Code a "-T" to reduce speed 
* Compatibility with windows
* Error message function 

<br>

<h3>👣 •  STEPS : </h3>

---

* __Compile the program__
```sh
g++ -Wall ./main.cpp -O2 -o cplusmap.bin -std=c++20
```
* __Run the program__
```sh
./cplusmap.bin -i {IP_ADDRESS}
```