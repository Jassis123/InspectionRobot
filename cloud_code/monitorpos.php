<?php

// 连主库
$hs = 'w.rdc.sae.sina.com.cn' . ':' . '3306';
$db = mysqli_connect($hs,'mlj1myy543','215wj14mlh03wylwzmhzl02lm02hyl4x3ywyz54h');

// 连从库
// $db = mysql_connect(SAE_MYSQL_HOST_S.':'.SAE_MYSQL_PORT,SAE_MYSQL_USER,SAE_MYSQL_PASS);

if ($db) {
	//echo "连上了。 ";
	// mysqli_get_server_version() ;
    mysqli_select_db( $db,'app_garbagesorting');

	$sqldata = "SELECT id, position_x, position_y,position_z FROM CarPos";
	$result = $db->query($sqldata);
	if ($result->num_rows > 0) {
	    // 输出数据
	    //echo "\nprint:\n";
	    //$row = $result->fetch_assoc()
        //$data = array('position_x' => $row["position_x"]." ",
	     //   		'position_y' => $row["position_y"]." ",
	     //   		'position_z' => $row["position_z"]."\n");
		//echo "id: " . $row["id"]. " - position_x: " . $row["position_x"]. "\tposition_y:" . $row["position_y"]."\tposition_z:" . $row["position_z"];
        while($row = $result->fetch_assoc()) {
	        
            echo "id:".$row["id"].",".$row["position_x"].",". $row["position_y"].",".$row["position_z"]." \n";

	        $data = //print_r(
	        	array('position_x' => $row["position_x"]." ",
	        		'position_y' => $row["position_y"]." ",
	        		'position_z' => $row["position_z"]."\n");
	        	//,true);
	    }
	} else {

	    echo "0 结果";
	}


	    // ...
	}else{
		 die('Could not connect: ' . mysqli_error());
	}

mysqli_close($db);

?>

