<?php


$x = fopen("F.txt", "w");

	if( $_GET['var'] =='on') 
	{ 
     header("Location: on.html");
     fwrite($x, '1');
	}
   elseif( $_GET['var'] =='off')
   {
	    
	  header("Location: off.html"); 
	  fwrite($x, '0');
   }   
fclose($x);
?>