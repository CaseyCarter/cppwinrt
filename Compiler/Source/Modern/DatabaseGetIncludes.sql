select substr(Name, 1, length(Name)-3) || 'h'
from Sources
where Include
order by Name