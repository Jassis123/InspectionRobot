<?php
function connect_db()
{
	// 连主库
$hs = 'w.rdc.sae.sina.com.cn' . ':' . '3306';
$db = mysqli_connect($hs,'mlj1myy543','215wj14mlh03wylwzmhzl02lm02hyl4x3ywyz54h');
if ($db) {
	echo "连上了。";
	mysqli_select_db( $db,'app_garbagesorting');
	return $db;
	}
else {
	echo "false connect". mysqli_error();
	exit ;
	};
}

?>


<?php

$db=connect_db();
// 连从库
// $db = mysql_connect(SAE_MYSQL_HOST_S.':'.SAE_MYSQL_PORT,SAE_MYSQL_USER,SAE_MYSQL_PASS);
echo "yes";
	$sqldata = "SELECT id, position_x, position_y,position_z FROM MyGuests";
	$result = $db->query($sqldata);
	file_put_contents('POS.txt', NULL);
	if ($result->num_rows > 0) {
	    // 输出数据
	    echo "\nprint:\n";
	    while($row = $result->fetch_assoc()) {
	        echo "id: " . $row["id"]. " - position_x: " . $row["position_x"]. "\tposition_y:" . $row["position_y"]."\tposition_z:" . $row["position_z"];
	        echo "\n";

	        $data = //print_r(
	        	array('position_x' => $row["position_x"]." ",
	        		'position_y' => $row["position_y"]." ",
	        		'position_z' => $row["position_z"]."\n");
	        	//,true);
	        file_put_contents('POS.txt', $data,FILE_APPEND | LOCK_EX);
	    }
	} else {

	    echo "0 结果";
	}


	    // ...
	

mysqli_close($db);

?>

