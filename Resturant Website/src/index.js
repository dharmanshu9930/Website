import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import reportWebVitals from './reportWebVitals';

import Header from './Components/Header';
import Main from './Components/Main';
import Offer from './Components/Offer';
// import Login from './Components/Login';
const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <React.StrictMode>
    <Header/>
    <Main/>
    <Offer/>
    {/* <Login/> */}
  </React.StrictMode>
);


reportWebVitals();
