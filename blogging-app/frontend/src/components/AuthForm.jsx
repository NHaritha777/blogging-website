import React, { useState } from 'react'
import API from '../api'


export default function AuthForm({ onClose, onAuth }){
const [mode, setMode] = useState('login')
const [name, setName] = useState('')
const [email, setEmail] = useState('')
const [password, setPassword] = useState('')
const [error, setError] = useState('')


async function submit(e){
e.preventDefault()
try{
if(mode === 'login'){
const res = await API.post('/auth/login', { email, password })
localStorage.setItem('token', res.data.token)
localStorage.setItem('user', JSON.stringify(res.data.user))
onAuth(res.data.user)
} else {
await API.post('/auth/register', { name, email, password })
setMode('login')
}
}catch(err){
setError(err?.response?.data?.message || 'Error')
}
}


return (
<div className="fixed inset-0 bg-black/30 flex items-center justify-center">
<div className="bg-white p-6 rounded shadow w-96">
<button className="float-right" onClick={onClose}>✕</button>
<h3 className="text-xl font-bold mb-4">{mode === 'login' ? 'Login' : 'Register'}</h3>
{error && <div className="text-red-600 mb-2">{error}</div>}
<form onSubmit={submit} className="space-y-3">
{mode === 'register' && (
<input value={name} onChange={e=>setName(e.target.value)} placeholder="Name" className="w-full p-2 border rounded" />
)}
<input value={email} onChange={e=>setEmail(e.target.value)} placeholder="Email" className="w-full p-2 border rounded" />
<input value={password} onChange={e=>setPassword(e.target.value)} placeholder="Password" type="password" className="w-full p-2 border rounded" />
<div className="flex justify-between items-center">
<button type="submit" className="px-4 py-2 bg-indigo-600 text-white rounded">{mode==='login'?'Login':'Register'}</button>
<button type="button" onClick={()=>setMode(mode==='login'?'register':'login')} className="text-sm text-indigo-600">{mode==='login'?'Create account':'Have an account?'}</button>
</div>
</form>
</div>
</div>
)
}