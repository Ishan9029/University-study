import React from 'react';
import {
  BrowserRouter,
  Routes,
  Route,
  Navigate,
  //useLocation,
} from 'react-router-dom';
import Login from './Login';
import User from './User';

/*function User() {
  const location = useLocation();
  const name = location.state?.name || 'Guest';
  return <h2>Welcome, {name}!</h2>;
}*/

export default function AppNavigate() {
  return (
    <BrowserRouter>
      <h1>React Routing Examples</h1>
      <Routes>
        <Route path="/" element={<Login />} />
        <Route path="/user" element={<User />} />
        <Route path="*" element={<Navigate to="/login" replace />} />
      </Routes>
    </BrowserRouter>
  );
}
