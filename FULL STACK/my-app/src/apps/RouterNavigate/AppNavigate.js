import React from 'react';
import {
  BrowserRouter,
  Routes,
  Route,
  Navigate,
  useLocation,
} from 'react-router-dom';
import Login from './Login';

function Home() {
  const location = useLocation();
  const name = location.state?.name || 'Guest';
  return <h2>Welcome, {name}!</h2>;
}

export default function AppNavigate() {
  return (
    <BrowserRouter>
      <h1>React Routing Examples</h1>
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/login" element={<Login />} />
        <Route path="*" element={<Navigate to="/login" replace />} />
      </Routes>
    </BrowserRouter>
  );
}
