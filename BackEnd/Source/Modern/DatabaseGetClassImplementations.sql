select substr(FullName, Name + 3), substr(FullName, 1, Name), DefaultInterface, replace(FullName, '::', '.')
from Classes