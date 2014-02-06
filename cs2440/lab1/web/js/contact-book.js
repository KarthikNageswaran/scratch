function ajax(url, method, data, successFunction) {
  var connection;

  if (XMLHttpRequest) {
    connection = new XMLHttpRequest();
  }
  else {
    connection = new ActiveXObject("Microsoft.XMLHTTP");
  }

  connection.open(method, url, true);
  connection.onreadystatechange = function() {
    if (connection.readyState != 4 || connection.status != 200) return;
    successFunction();
  };
  connection.send(data);
}

