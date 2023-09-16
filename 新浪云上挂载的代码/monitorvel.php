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

	$sqldata = "SELECT id, status FROM velctrl";
	$result = $db->query($sqldata);
	if ($result->num_rows > 0) {
	    $row = $result->fetch_assoc();
        echo $row["status"]." <br>";
	    
	} else {

	    echo "0 结果";
	}


	    // ...
	}else{
		 die('Could not connect: ' . mysqli_error());
	}

mysqli_close($db);

?>

