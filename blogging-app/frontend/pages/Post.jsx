import React, { useEffect, useState } from 'react'
import { useParams } from 'react-router-dom'
import API from '../api'


export default function Post(){
const { id } = useParams()
const [post, setPost] = useState(null)


useEffect(()=>{
API.get(`/posts/${id}`).then(res=> setPost(res.data)).catch(console.error)
},[id])


if(!post) return <div>Loading...</div>


return (
<article className="max-w-3xl mx-auto bg-white p-6 rounded shadow">
<h1 className="text-2xl font-bold mb-2">{post.title}</h1>
<div className="text-sm text-gray-500 mb-4">By {post.author?.name} • {new Date(post.createdAt).toLocaleString()}</div>
<div className="prose" dangerouslySetInnerHTML={{ __html: post.content }} />
</article>
)
}