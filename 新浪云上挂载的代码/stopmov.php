<?php

// 连主库
$hs = 'w.rdc.sae.sina.com.cn' . ':' . '3306';
$db = mysqli_connect($hs,'mlj1myy543','215wj14mlh03wylwzmhzl02lm02hyl4x3ywyz54h');

// 连从库
// $db = mysql_connect(SAE_MYSQL_HOST_S.':'.SAE_MYSQL_PORT,SAE_MYSQL_USER,SAE_MYSQL_PASS);

//$data=(int)$_POST['movpos'];
$data=1;
if ($db) {
	echo "连上了。";
	// mysqli_get_server_version() ;
    mysqli_select_db( $db,'app_garbagesorting');
    
    
    $sql = "update velctrl set status=0 where id=1"; 	
	if ($db->query($sql) === TRUE) {
	    echo "新记录更新成功\n";
	} else {
	    echo "Error: " . $sql . "<br>" . $db->error;
	}
    
    //$sql = "INSERT INTO CarMov (position_x, position_y, position_z)
	 // VALUES ($data, 11.1, 12.3)";
	 
	 //if ($db->query($sql) === TRUE) {
	  //    echo "新记录插入成功";
	  //} else {
	  //    echo "Error: " . $sql . "<br>" . $db->error;
	 // }
    
    //echo "recevie_data:";
	//echo $_POST['position_x'];
}
	mysqli_close($db);

?>