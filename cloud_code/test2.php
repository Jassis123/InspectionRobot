<?php



$db=new mysqli('36.248.247.250:40582','ljs','123456','testsql');


if ($db) {
	echo "连上了。";
	// mysqli_get_server_version() ;
    mysqli_select_db( $db,'testsql');
    // 使用 sql 创建数据表
 //    $dropsql="DROP TABLE MyGuests";
 //    $retval = mysqli_query($db,$dropsql);
	// if(! $retval )
	// {
	//   die('数据表删除失败: ' . mysqli_error($conn));
	// }
	// echo "数据表删除成功\n";




	$sqldata = "SELECT id, position_x, position_y,position_z FROM MyGuests";
	$result = $db->query($sqldata);
	 
	if ($result->num_rows > 0) {
	    // 输出数据
	    echo "\nprint:\n";
	    while($row = $result->fetch_assoc()) {
	        echo "id: " . $row["id"]. " - position_x: " . $row["position_x"]. "\tposition_y:" . $row["position_y"]."\tposition_z:" . $row["position_z"];
	        echo "\n";

	        $data = print_r(array('position_x' => $row["position_x"],'position_y' => $row["position_y"],'position_z' => $row["position_z"] ),true);
	        file_put_contents('POS.txt', $data);
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

