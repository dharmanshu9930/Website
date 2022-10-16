import React from 'react';
import data from './Data.json';


const Main = () => {

  // SignIn, Login and Cross Button function ------------------------------------->
  const login = (e) => {
    e.preventDefault();
    document.querySelector(".loginContainer").classList.toggle("active");
    document.querySelector(".search-form").classList.remove("active");
    document.querySelector(".navbarActive").classList.remove("active");
    document.querySelector(".signContainer").classList.remove("active");
  }
  const cross = () => {
    document.querySelector("#detailContainer").style = "display:none";
    document.querySelector(".signContainer").classList.remove("active");
    document.querySelector(".loginContainer").classList.remove("active");
    document.querySelector("#emailsign").value = "";
    document.querySelector("#pass").value = "";
    document.querySelector("#confirm").value = "";
    document.querySelector("#warning").style = "display:none";
    
  }
  const sign = (e) => {
    e.preventDefault();
    document.querySelector(".signContainer").classList.toggle("active");
    document.querySelector(".search-form").classList.remove("active");
    document.querySelector(".navbarActive").classList.remove("active");
    document.querySelector(".loginContainer").classList.remove("active");
  }

  // LogIn function ---------------------------------------------->
  const loginDetail = (e) => {
    e.preventDefault();
    const emailLog = document.querySelector("#emailLog").value.toLowerCase();
    const passlogin = document.querySelector("#passlogin").value;
    if (emailLog === "" || passlogin === "") {
      document.querySelector("#success").innerHTML = "Fill all the fields ";
      document.querySelector("#success").style = "color:red;font-size:1.3rem;"
    } else {
      data.map((val) => {
        if (val.email === emailLog && val.pass === passlogin) {
          document.querySelector("#success").innerHTML = `Welcome ${val.name}`;
          document.querySelector("#success").style = "color:tomato;font-size:1.3rem;"
          document.querySelector(".loginContainer").classList.remove("active");
          document.querySelector("#loginDText").innerHTML = `${val.name}`;
          document.querySelector("#signDText").style.display = "none";
          document.querySelector("#logDout").innerHTML = `<i class="fa-solid fa-right-from-bracket"></i>`;
          document.querySelector("#loginText").innerHTML = `${val.name}`;
          document.querySelector("#signText").style.display="none";
          document.querySelector("#logout").innerHTML = `<i class="fa-solid fa-right-from-bracket"></i>`;
        }
      })
    }
  }

  // Sign In function --------------------------------------------------------->
  const signDetail = (e) => {
    e.preventDefault();
    const nam = document.querySelector("#name").value;
    const emailsign = document.querySelector("#emailsign").value.toLowerCase();
    const pass = document.querySelector("#pass").value;
    const confirm = document.querySelector("#confirm").value;
    if (nam==="" ||emailsign === "" || pass === "" || confirm === "") {
      document.querySelector("#warn").innerHTML = "Fill all the fields ";
      document.querySelector("#warn").style = "color:red;font-size:1.3rem;"
    } else if (pass !== confirm) {
      document.querySelector("#warn").innerHTML = "Re-entered password didn't matched";
      document.querySelector("#warn").style = "color:red;font-size:1rem;"
    } else {
      document.querySelector("#warn").innerHTML = `Thank You for Signing In. <h5> Please Login to enjoy services</h5>`;
      document.querySelector("#warn").style = "color:green";
      document.querySelector("#emailsign").value = "";
      document.querySelector("#pass").value = "";
      document.querySelector("#confirm").value = "";
      document.querySelector("#name").value = "";
      const obj = { name: nam, email: emailsign, pass: pass };
      data.push(obj);
      document.querySelector(".loginContainer").classList.add("active");
      document.querySelector(".signContainer").classList.remove("active");
    }
  }

 

  return (
    <>
      <section id="main" className='main'>
        <div className='content'>
          <h3>Feeling <span> Hungry</span></h3>
          <h1><span> Grab </span>food from Us</h1>
          <a href=".about" className='btn'> Know About<span> US</span> </a>
        </div>


        {/* Login Section */}
        <div className="loginContainer">
          <i className="fa-solid fa-xmark" onClick={cross}></i>
          <form className="login">
            <p className="login-text" style={{ fontSize: "2rem", fontWeight: "800", marginBottom: "5%" }}>Log In</p>

            <input type="email" placeholder="Email" name="email" id='emailLog' required />

            <input type="password" placeholder="Password" name="password" id='passlogin' required />
            <p id="success"></p>
            <button name="submit" className="btn btnLog" onClick={loginDetail}>Login</button>
            <p className="login-register-text">Don't have an account? <a href="=" onClick={sign}>Register Here</a></p>
          </form>
        </div>

        {/* SignUP section */}
        <div className="signContainer" >
          <i className="fa-solid fa-xmark" onClick={cross}></i>
          <form className="sign">
            <p style={{ fontSize: "2rem", fontWeight: "800", marginBottom: "5%" }}>Sign UP</p>
            <input type="email" placeholder="Your Name" name="text" id='name' required />
            <input type="email" placeholder="Email" name="email" id='emailsign' required />
            <input type="password" placeholder="Password" name="password" id="pass" required />
            <input type="password" placeholder=" Re-Enter Password" name="password" id="confirm" required />
            <p id="warn"></p>
            <button name="submit" className="btn btnSign" onClick={signDetail} >SignUP</button>
            <p className="login-register-text">Already have an account? <a href="=" onClick={login}>Login Here ..</a></p>
          </form>
        </div>

        {/* Details Section */}
        <div id="detailContainer">
          <i className="fa-solid fa-xmark" onClick={cross}></i>
          <div id="abou">
          </div>
          <div id="addres">
          </div>

          <div id="extra">
          <h3 style={{color:"rgb(106, 86, 216)",textDecoration:"underline",marginTop:"1rem",marginBottom:"2rem",fontSize:"1.5rem"}}>Operating Hours</h3>
            <div id="opH">

            </div>
            <div >
              <h3 style={{color:"rgb(106, 86, 216)",textDecoration:"underline",marginTop:"2rem",textTransform:"uppercase",fontSize:"1.5rem"}}>Review</h3>
              <div id="review"></div>


            </div>
          </div>
        </div>
      </section>
    </>
  )
}

export default Main
