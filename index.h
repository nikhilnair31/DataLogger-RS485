const char MAIN_page[] PROGMEM = R"=====(
<!doctype html>
<html>

  <style>
      a{color: #f2f4f8;text-align:center;font-family: Comfortaa; }
      h2{margin-top: 15%;  color: #585e6b;text-align:center;font-family: Comfortaa; font-size: 40px;}
      img{display:block; margin: 0 auto; position:relative; margin-top: 10%; }
      body{background: #f2f4f8; }
      canvas{-moz-user-select: none;-webkit-user-select: none;-ms-user-select: none;}
      table {margin-left: 2.5%;margin-right: 0px;}
      button {margin-left: 50%; text-align:center;font-family: Comfortaa; }
      #dataTable::-webkit-scrollbar { display: scroll; }
      #dataTable::-webkit-scrollbar {width: 7.5px;}
      #dataTable::-webkit-scrollbar-track { background: rgba(70, 70, 70, 0.1); box-shadow: inset 0 0 1px rgba(100, 100, 100, 0.5); border-radius: 10px;}
      #dataTable::-webkit-scrollbar-thumb {background: rgba(44, 44, 44, 0.2); border-radius: 10px;}
      #dataTable::-webkit-scrollbar-thumb:hover {background: rgba(45, 45, 45,0.3);}
      #dataTable {margin-left: 12.5px; display: block;font-family: "Comfortaa";color: rgb(255, 255, 255);border-collapse: collapse;height: 275px;width: 350px;background: rgba( 0, 0, 0 , 0);overflow-y: scroll;}
      #dataTable td, #dataTable th {border: 0px solid rgba(255, 255, 255, 1);color: rgb(115, 120, 130);padding: 7.5px; text-align: center;width: 20%;}
      #dataTable td {width: 20px;}
      #dataTable tr:nth-child(even){color: rgb(255, 255, 255); background-color: rgba(249, 252, 254, 1); width: 50%;}
      #dataTable tr:hover {color: rgb(255, 255, 255); background-color: rgba(255, 255, 255,0.15); width: 50%;}
      #dataTable th {padding-top: 12px;padding-bottom: 12px;width: 50%;text-align: center;background-color: rgb(250, 250, 250);color: white;}
      #dataTable thead:nth-child(even){color: rgb(255, 255, 255); background-color: rgba(249, 252, 254, 1); width: 50%;}
      #dataTable thead:hover {color: rgb(255, 255, 255); background-color: rgba(255, 255, 255,0.15); width: 50%;}
      #dataTableB::-webkit-scrollbar { display: scroll; }
      #dataTableB::-webkit-scrollbar {width: 7.5px;}
      #dataTableB::-webkit-scrollbar-track { background: rgba(70, 70, 70, 0.1); box-shadow: inset 0 0 1px rgba(100, 100, 100, 0.5); border-radius: 10px;}
      #dataTableB::-webkit-scrollbar-thumb {background: rgba(44, 44, 44, 0.2); border-radius: 10px;}
      #dataTableB::-webkit-scrollbar-thumb:hover {background: rgba(45, 45, 45,0.3); }
      #dataTableB {margin-left: 0px; margin-right: 20px; display: block;font-family: "Comfortaa";color: rgb(255, 255, 255);border-collapse: collapse;height: 275px;width: 300px;background: rgba( 0, 0, 0 , 0);overflow-y: scroll;}
      #dataTableB td, #dataTable th {border: 0px solid rgba(255, 255, 255, 1);color: rgb(115, 120, 130);padding: 7.5px; text-align: center;width: 30%;}
      #dataTableB tr:nth-child(even){color: rgb(255, 255, 255); background-color: rgba(249, 252, 254, 1); width: 50%;}
      #dataTableB tr:hover {color: rgb(255, 255, 255); background-color: rgba(255, 255, 255,0.15); width: 50%;}
      #dataTableB th {padding-top: 12px;padding-bottom: 12px;text-align: center;background-color: rgb(250, 250, 250);color: white;}
      #delete_button {border: 0px solid rgba(0, 0, 0,1); margin-left: 47.5%; float:center; position: relative; text-align: center; width:65px; height:35px; font-size: 10px; color:rgb(51, 51, 51, 1) ;background: rgba(235, 235, 240, 1);}
      #download_button {border: 0px solid rgba(0, 0, 0,1); margin-left: 0%; float:center; position: relative; text-align: center; width:65px; height:35px; font-size: 10px; color:rgba(51, 51, 51, 1) ;background: rgba(235, 235, 240, 1);}
      #refreshgraph_button {border: 0px solid rgba(0, 0, 0,1); margin-left: 0%; float:center; position: relative; text-align: center; width:65px; height:35px; font-size: 10px; color:rgba(51, 51, 51, 1) ;background: rgba(235, 235, 240, 1);}
      #splashscreen {z-index: 1; position: absolute; display:block; margin: 0 auto; position:fixed;top:0px;left:0px;height:100%;width:100%;background: rgba(245, 245, 245, 1); }
      .Title {text-align:left; margin-left: 1.5%; color: #342d46; font-family: Comfortaa; font-size: 25px;}
      .loader {margin: auto; position:relative; margin-top: 5%; top:0px;left:0px;height:100%;width:100%;text-align:center; border: 5px solid rgba( 25, 25, 25 , 0.4);border-top: 5px solid #db346c;border-radius: 50%;width: 25px;height: 25px;animation: spin 1.5s linear infinite;}
      @keyframes spin {0% { transform: rotate(0deg); }100% { transform: rotate(360deg); }}
  </style>

  <head>
    <title style="font-family: Comfortaa;">RADDV</title>
    <script src="https://www.gstatic.com/firebasejs/6.0.2/firebase-app.js"></script>
    <script src="https://www.gstatic.com/firebasejs/6.0.2/firebase-database.js"></script>
    <script src = "https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.7.3/Chart.min.js"></script>  
    <script src="http://code.jquery.com/jquery-1.11.0.min.js"></script>
    
    <br>
    <div class="Title">Remote Access Dryer Data Visualization
        <button id="delete_button" onclick="deleteAll()">Delete</button>
        <button id="download_button" onclick="downloadURI()">Download</button>
        <button id="refreshgraph_button" onclick="refreshPage()">Refresh</button>
        <input class="checkbox" type="checkbox" id="autoRefresh_checkbox" name="autoRefresh" value="?">
    </div>
    <br>
  </head>

  <body>

      <div id="splashscreen">
          <h2>Welcome</h2>
          <!-- Hiding this image for now <!img src="https://firebasestorage.googleapis.com/v0/b/biit-aff4a.appspot.com/o/hpl.png?alt=media&token=9aaa0bbd-883b-4acd-8ce0-39e089fa02c0"> -->
          <div class="loader"></div>
          <a href="#" class="enter_link"></a>
      </div>
      
      <div>
        <div class="chart-container" style = "position: absolute; height:300px; width:47.5%; ">
            <canvas id="Chart1" style = "position: relative; width:350px; margin-left: 2%; background: #fff;border-radius: 5px;"></canvas>
        </div>
        <div class="chart-container2" style = "position: relative; height:300px; width:47.5%; ">
            <canvas id="Chart2" style = "position: relative; width:350px; margin-left: 107.5%; background: #fff;border-radius: 5px;"></canvas>
        </div>
      </div>

      <br>

      <div>
        <table id="dataTable" style="float:left">
          <thead><th style="border: 0px solid rgba(0, 0, 0,0.5);color: rgb(100, 100, 100);width: 100px; padding: 10px; text-align: center;">Time</th>
            <th style="border: 0px solid rgba(0, 0, 0,0.5);color: rgb(100, 100, 100);width: 50px; padding: 10px; text-align: center;"><input type="checkbox" id="showT4" name="showT4" onclick="showT(3)"><br> T4</th>
              <th style="border: 0px solid rgba(0, 0, 0,0.5);color: rgb(100, 100, 100);width: 50px; padding: 10px; text-align: center;"><input type="checkbox" id="showT3" name="showT3" onclick="showT(2)"><br> T3</th>
                <th style="border: 0px solid rgba(0, 0, 0,0.5);color: rgb(100, 100, 100);width: 50px; padding: 10px; text-align: center;"><input type="checkbox" id="showT2" name="showT2" onclick="showT(1)"><br> T2</th>
                  <th style="border: 0px solid rgba(0, 0, 0,0.5);color: rgb(100, 100, 100);width: 50px; padding: 10px; text-align: center;"><input type="checkbox" id="showT1" name="showT1" onclick="showT(0)"><br> T1</th>
                  <th style="border: 0px solid rgba(0, 0, 0,0.5);color: rgb(100, 100, 100);width: 100px; padding: 10px; text-align: center;">Count</th></thead>
          <tbody> <td>-:-:-</td> <td>-</td> <td>-</td> <td>-</td> <td>-</td> <td>-</td> </tbody>        
        </table>
        
        <table id="dataTableB" style="float:right">
          <thead><th style="border: 0px solid rgba(0, 0, 0,0.5);color: rgb(100, 100, 100);width: 100px; padding: 10px; text-align: center;">Time</th>
            <th style="border: 0px solid rgba(0, 0, 0,0.5);color: rgb(100, 100, 100);width: 50px; padding: 10px; text-align: center;"><input type="checkbox" id="showP3" name="showP3" onclick="showP(2)"><br> P3</th>
              <th style="border: 0px solid rgba(0, 0, 0,0.5);color: rgb(100, 100, 100);width: 50px; padding: 10px; text-align: center;"><input type="checkbox" id="showP2" name="showP2" onclick="showP(1)"><br> P2</th>
                <th style="border: 0px solid rgba(0, 0, 0,0.5);color: rgb(100, 100, 100);width: 50px; padding: 10px; text-align: center;"><input type="checkbox" id="showP1" name="showP1" onclick="showP(0)"><br> P1</th>
                  <th style="border: 0px solid rgba(0, 0, 0,0.5);color: rgb(100, 100, 100);width: 100px; padding: 10px; text-align: center;">Count</th></thead>
          <tbody> <td>-:-:-</td> <td>-</td> <td>-</td> <td>-</td> <td>-</td> </tbody>
        </table>
      </div>

      <br>

      <script>
        var time;
        var j = i = 0;
        var countA = [];
        var countB = [];
        var valuesT1 = [];var valuesT2 = [];var valuesT3 = [];var valuesT4 = [];
        var valuesP1 = [];var valuesP2 = [];var valuesP3 = [];
        var timeStamp = [];
        var Chart1,Chart2;

        var config = {apiKey: "AIzaSyD50fXVWnUPQFJdmwkFiZ6q-kLgf_Ipwqw",authDomain: "biit-aff4a.firebaseapp.com",databaseURL: "https://biit-aff4a.firebaseio.com",projectId: "biit-aff4a",storageBucket: "biit-aff4a.appspot.com",messagingSenderId: "671398131902"};
        firebase.initializeApp(config);

        var rootRef = firebase.database().ref();
        var pRef = firebase.database().ref().child('P');
        var tRef = firebase.database().ref().child('T');
        var timeRef = firebase.database().ref().child('Time');

        function showInitTable(){
            timeRef.once('value', function(snap) {
                var childData = snap.val();
                var keys = Object.keys(childData);
                for(var z=0; z<keys.length; z++){
                  var k = keys[z];
                  if(childData[k] != null){
                    time = childData[k];
                    timeStamp.push(time);
                  }
                  else{
                    console.log("Null");
                  }
                }
            });
            tRef.once('value', function(snap) {
              var childData = snap.val();
              var keys = Object.keys(childData);
              var table = document.getElementById("dataTable");
              var idk = Object.keys(childData[keys[0]]);
              for(var q=0; q<idk.length; q++){
                var row = table.insertRow(1);
                var cell0 = row.insertCell(0);
                cell0.innerHTML = timeStamp[0];
                for(var z=0; z<keys.length; z++){ //fills a row's data
                  var k = keys[z];
                  //console.log("keys : "+keys); //P1 P2 P3
                  //console.log("k : "+k); //P1 or P2 or P3
                  if(childData[k] != null){
                    var x = childData[k];
                    var keyx = Object.keys(x);
                    //console.log(x); //adress and value
                    //console.log("keyx : "+keyx); //addresses
                    var address = keyx[q];
                    var y = x[address];
                    //console.log("z : "+z); //d
                    //console.log("address : "+address); //address
                    //console.log("y : "+y); //value
                    if(k.localeCompare("T1") == 0){ valuesT1.push(y); }
                    else if(k.localeCompare("T2") == 0){ valuesT2.push(y); }
                    else if(k.localeCompare("T3") == 0){ valuesT3.push(y); }
                    else if(k.localeCompare("T4") == 0){ valuesT4.push(y); }
                    var cell0 = row.insertCell(1);
                    cell0.innerHTML = y;
                    showGraph();
                  }
                  else{console.log("Null");}
                }
                countA.push(++i);
                var cell4 = row.insertCell(5);
                cell4.innerHTML = i;
              }
            });
            pRef.once('value', function(snap) {
                var childData = snap.val();
                var keys = Object.keys(childData);
                var table = document.getElementById("dataTableB");
                var idk = Object.keys(childData[keys[0]]);
                for(var q=0; q<idk.length; q++){
                  var row = table.insertRow(1);
                  var cell0 = row.insertCell(0);
                  cell0.innerHTML = timeStamp[0];
                  for(var z=0; z<keys.length; z++){ //fills a row's data
                    var k = keys[z];
                    //console.log("keys : "+keys); //P1 P2 P3
                    //console.log("k : "+k); //P1 or P2 or P3
                    if(childData[k] != null){
                      var x = childData[k];
                      var keyx = Object.keys(x);
                      //console.log(x); //adress and value
                      //console.log("keyx : "+keyx); //addresses
                      var address = keyx[q];
                      var y = x[address];
                      //console.log("z : "+z); //d
                      //console.log("address : "+address); //address
                      //console.log("y : "+y); //value
                      if(k.localeCompare("P1") == 0){ valuesP1.push(y); }
                      else if(k.localeCompare("P2") == 0){ valuesP2.push(y); }
                      else if(k.localeCompare("P3") == 0){ valuesP3.push(y); }
                      var cell0 = row.insertCell(1);
                      cell0.innerHTML = y;
                      showGraph();
                    }
                    else{console.log("Null");}
                  }
                  countB.push(++j);
                  var cell4 = row.insertCell(4);
                  cell4.innerHTML = j;
                }
            });
        };

        function showUpdatedTable(){
            timeRef.endAt().limitToLast(1).once("child_added", function(snap) {
                var childData = snap.val();
                var keys = Object.keys(childData);
                for(var z=0; z<keys.length; z++){
                  var k = keys[z];
                  if(childData[k] != null){
                    time = childData[k];
                    timeStamp.push(time);
                  }
                  else{console.log("Null");}
                }
            });
            pRef.endAt().limitToLast(1).once("child_added", function(snap) {
                var childData = snap.val();
                var keys = Object.keys(childData);
                for(var z=0; z<keys.length; z++){
                  var k = keys[z];
                  if(childData[k] != null){
                    var x = childData[k];
                    valuesT1.push(x);valuesT2.push(x*(Math.random()*(1.5-1)+1));valuesT3.push(x*(Math.random()*(1.5-1)+1));valuesT4.push(x*(Math.random()*(1.5-1)+1));
                    countA.push(++i);
                    //timeStamp.push(time);
                    showGraph();
                    var table = document.getElementById("dataTable");
                    var row = table.insertRow(1); //Add after headings
                    var cell1 = row.insertCell(0);var cell2 = row.insertCell(1);var cell3 = row.insertCell(2);var cell4 = row.insertCell(3); cell5 = row.insertCell(4);var cell6 = row.insertCell(5);
                    cell1.innerHTML = timeStamp[z];cell2.innerHTML = x;cell3.innerHTML = x+1;cell4.innerHTML = x+2;cell5.innerHTML = x+3;cell6.innerHTML = i;
                  }
                  else{ console.log("Null");}
                }
            });
            tRef.endAt().limitToLast(1).once("child_added", function(snap) {
                var childData = snap.val();
                var keys = Object.keys(childData);
                for(var z=0; z<keys.length; z++){
                  var k = keys[z];
                  if(childData[k] != null){
                    var x = childData[k];
                    valuesP1.push(x);valuesP2.push(x*(Math.random()*(1.5-1)+1));valuesP3.push(x*(Math.random()*(1.5-1)+1));
                    countB.push(++j);
                    showGraph();
                    var table = document.getElementById("dataTableB");
                    var row = table.insertRow(1)
                    var cell1 = row.insertCell(0);var cell2 = row.insertCell(1);var cell3 = row.insertCell(2);var cell4 = row.insertCell(3);var cell5 = row.insertCell(4);
                    cell1.innerHTML = time;cell2.innerHTML = x;cell3.innerHTML = x+1;cell4.innerHTML = x+2;cell5.innerHTML = j;
                  }
                  else{console.log("Null");}
                }
            });
        };

        function showGraph()
        {
            var ctx = document.getElementById("Chart1").getContext('2d');
            var cty = document.getElementById("Chart2").getContext('2d');

            var gradientT1 = ctx.createLinearGradient(0, 0, 0, 300); var gradientT2 = ctx.createLinearGradient(0, 0, 0, 300);
            var gradientT3 = ctx.createLinearGradient(0, 0, 0, 300); var gradientT4 = ctx.createLinearGradient(0, 0, 0, 300);
            gradientT1.addColorStop(0, 'rgba(50, 190, 175, 0.25)'); gradientT1.addColorStop(1, 'rgba(255,255,255,0.1)');
            gradientT2.addColorStop(0, 'rgba(135, 60, 175,0.25)'); gradientT2.addColorStop(1, 'rgba(255,255,255,0.1)');
            gradientT3.addColorStop(0, 'rgba(10, 115, 170,0.25)'); gradientT3.addColorStop(1, 'rgba(255,255,255,0.1)');
            gradientT4.addColorStop(0, 'rgba(5, 95, 170,0.25)'); gradientT4.addColorStop(1, 'rgba(255,255,255,0.1)');
            var gradientP1 = cty.createLinearGradient(0, 0, 0, 400); var gradientP2 = cty.createLinearGradient(0, 0, 0, 400);
            var gradientP3 = cty.createLinearGradient(0, 0, 0, 400);
            gradientP1.addColorStop(0, 'rgba(50, 190, 175,0.5)'); gradientP1.addColorStop(1, 'rgba(255,255,255,0.05)');
            gradientP2.addColorStop(0, 'rgba(60, 130, 170,0.5)'); gradientP2.addColorStop(1, 'rgba(255,255,255,0.05)');
            gradientP3.addColorStop(0, 'rgba(135, 60, 175,0.5)'); gradientP3.addColorStop(1, 'rgba(255,255,255,0.05)');

            Chart.defaults.global.defaultFontFamily = 'Comfortaa';
            Chart.defaults.global.animation.duration = 0;
            Chart1 = new Chart(ctx, {
                type: 'line',
                data: {
                    labels: countA,
                    datasets: [
                      {fontColor: 'black',label: "T1",fill: true, backgroundColor: gradientT1, borderColor: 'rgba(50, 190, 175, 1)',data: valuesT1,},
                      {fontColor: 'black',label: "T2",fill: true, backgroundColor: gradientT3, borderColor: 'rgba(10, 115, 170, 1)',data: valuesT2,},
                      {fontColor: 'black',label: "T3",fill: true, backgroundColor: gradientT4, borderColor: 'rgba(5, 95, 170, 1)',data: valuesT3,},
                      {fontColor: 'black',label: "T4",fill: true, backgroundColor: gradientT2, borderColor: 'rgba(135, 60, 175, 1)',data: valuesT4,}]
                },
                options: {
                    legend: { display: false, labels: {fontColor: "white",} },
                    title: { display: false, text: "Stuff", fontColor: 'white' },
                    maintainAspectRatio: false,
                    elements: { line: {tension: 0.3} },
                    scales: { xAxes: [{ gridLines: { display: true ,color: "rgba(0,0,0,0.25)" }, ticks: { fontColor: 'rgba(100,100,100,1)', autoSkip: true, maxRotation: 0, minRotation: 0 } }],yAxes: [{ gridLines: { display: true ,color: "rgba(0, 0, 0, 0.25)" }, ticks: { beginAtZero:true, fontColor: 'rgba(100,100,100,1)' } }] }
                }
            });
            Chart2 = new Chart(cty, {
                type: 'line',
                data: {
                    labels: countA,
                    datasets: [
                      {fontColor: 'black',label: "P1",fill: true,backgroundColor: gradientP1, borderColor: 'rgba(50, 190, 175, 1)',data: valuesP1,},
                      {fontColor: 'black',label: "P2",fill: true,backgroundColor: gradientP2, borderColor: 'rgba(60, 130, 170, 1)',data: valuesP2,},
                      {fontColor: 'black',label: "P3",fill: true,backgroundColor: gradientP3, borderColor: 'rgba(135, 60, 175, 1)',data: valuesP3,}]
                },
                options: {
                    legend: { display: false, labels: {fontColor: "white",} },
                    title: { display: false, text: "Stuff", fontColor: 'white' },
                    maintainAspectRatio: false,
                    elements: { line: {tension: 0.3} },
                    scales: { xAxes: [{ gridLines: { display: true ,color: "rgba(0,0,0,0.25)" }, ticks: { fontColor: 'rgba(100,100,100,1)', autoSkip: false, maxRotation: 0, minRotation: 0 } }],yAxes: [{ gridLines: { display: true ,color: "rgba(0, 0, 0, 0.25)" }, ticks: { beginAtZero:true, fontColor: 'rgba(100,100,100,1)' } }] }
                }
            });
        }

        window.onload = function() {
          document.getElementById("autoRefresh_checkbox").checked = false;
          document.getElementById("showT1").checked = true;document.getElementById("showT2").checked = true;document.getElementById("showT3").checked = true;document.getElementById("showT4").checked = true;    
          document.getElementById("showP1").checked = true;document.getElementById("showP2").checked = true;document.getElementById("showP3").checked = true;
          setTimeout(function() {
            $('.enter_link').parent('#splashscreen').fadeOut(500);
            setTimeout(function() {
              showInitTable();
            }, 250);     
          }, 2000);
        };
 
        setInterval(function() {
          if(document.getElementById("autoRefresh_checkbox").checked == true){
            setInterval(function() {
              refreshPage();
            }, 12000);
          }
        }, 12000);

        function showT(index) {
          var meta1 = Chart1.getDatasetMeta(index);
          meta1.hidden = meta1.hidden === null? !Chart1.data.datasets[index].hidden : null;
          Chart1.update();
        }

        function showP(index) {
          var meta2 = Chart2.getDatasetMeta(index);
          meta2.hidden = meta2.hidden === null? !Chart2.data.datasets[index].hidden : null;
          Chart2.update();
          console.log(meta2);
        }

        function refreshPage() {
          location.reload();
        }

        function downloadURI() {
          $.ajax({
            type: "GET",
            url: "https://biit-aff4a.firebaseio.com/.json",
            success: function(data) {
              console.log(data);
              var bl = new Blob([JSON.stringify(data)], {type: "text/plain"});
              var a = document.createElement("a");
              a.href = URL.createObjectURL(bl);
              a.download = "JSONfile.json";
              a.hidden = true;
              document.body.appendChild(a);
              a.innerHTML = "XXX";
              a.click();
            },
            dataType: "json"
          });
        }

        function deleteAll(){
          rootRef.orderByChild('Data').once('value', snapshot => {
            const updates = {};
            snapshot.forEach(child => updates[child.key] = '');
            rootRef.update(updates);
            });
        };

        function getInitData() {
          var xhttpD = new XMLHttpRequest(); 
          xhttpD.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
              var DValue = this.responseText;
              console.log("D : "+DValue);
            }
            else if (this.status == 303 ) {
            }
          };
          xhttpD.open("GET", "readD", true); //Handle readADC server on ESP8266
          xhttpD.send();     
        }
        
        function getData() {
          var time, AValue, BValue;
          var xhttpA = new XMLHttpRequest();
          var xhttpB = new XMLHttpRequest();

          time = (new Date().toLocaleTimeString()).slice(0, -3);

          xhttpA.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
              var AValue = this.responseText; 
              valuesT1.push(AValue);
              timeStamp.push(time);
              //showGraph();
            }
            else if (this.status == 303 ) {
              //console.log("Wait");
            }
          };
          
          xhttpB.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
              var BValue = this.responseText; 
              valuesB.push(BValue);
              //showGraph();
            }
            else if (this.status == 303 ) {
              //console.log("Wait");
            }
          };

          xhttpA.open("GET", "readA", true); //Handle readADC server on ESP8266
          xhttpB.open("GET", "readB", true); //Handle readADC server on ESP8266
          xhttpB.send();
          xhttpA.send();
        }
          
      </script>
  </body>

</html>

)=====";


