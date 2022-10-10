import LoginPage from './LoginPage';
import './App.css';
import Navbar from './Navbar';
import SignUp from './SignUp'
import Home from './Home'
import 'react-router-dom'
import { Route, BrowserRouter,Routes } from 'react-router-dom';
function App() {
return (
    <BrowserRouter>
      <div >
        <Navbar/>
      <Routes>
        <Route path='/' element={<Home/>}/>
        <Route path='/signin' element={<SignUp/>}/>
        <Route path='/login' element={<LoginPage/>}/> 
        </Routes>
        </div>
        </BrowserRouter>
  );
}

export default App;
