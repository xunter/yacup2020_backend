select count(*) as res
from (
 select distinct ID 
 from tmp
) t
