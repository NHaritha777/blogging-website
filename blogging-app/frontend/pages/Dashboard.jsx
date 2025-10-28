import React, { useEffect, useState } from 'react'
import API from '../api'

export default function Dashboard() {
  const [posts, setPosts] = useState([])
  const [title, setTitle] = useState('')
  const [content, setContent] = useState('')

  // Fetch logged-in user's posts
  useEffect(() => {
    API.get('/posts/my')
      .then(res => setPosts(res.data))
      .catch(err => console.error('Error fetching posts:', err))
  }, [])

  // Create a new post
  async function createPost(e) {
    e.preventDefault()
    try {
      const res = await API.post('/posts', { title, content })
      setPosts(prev => [res.data, ...prev])
      setTitle('')
      setContent('')
    } catch (err) {
      console.error('Error creating post:', err)
    }
  }

  return (
    <div className="min-h-screen bg-gradient-to-br from-purple-100 via-white to-blue-100 flex flex-col items-center py-10 px-4">
      <h1 className="text-3xl font-bold text-gray-800 mb-6">📝 My Blog Dashboard</h1>

      {/* New Post Form */}
      <form
        onSubmit={createPost}
        className="w-full max-w-lg bg-white shadow-lg rounded-2xl p-6 mb-10"
      >
        <h2 className="text-xl font-semibold mb-4 text-gray-700">Create New Post</h2>

        <input
          type="text"
          placeholder="Post Title"
          value={title}
          onChange={(e) => setTitle(e.target.value)}
          className="w-full border border-gray-300 rounded-lg p-2 mb-4 focus:outline-none focus:ring-2 focus:ring-blue-400"
          required
        />

        <textarea
          placeholder="Write your content..."
          value={content}
          onChange={(e) => setContent(e.target.value)}
          className="w-full border border-gray-300 rounded-lg p-2 mb-4 h-32 resize-none focus:outline-none focus:ring-2 focus:ring-blue-400"
          required
        />

        <button
          type="submit"
          className="w-full bg-blue-600 text-white py-2 rounded-lg hover:bg-blue-700 transition duration-300"
        >
          Publish Post
        </button>
      </form>

      {/* Posts List */}
      <div className="w-full max-w-2xl space-y-6">
        {posts.length === 0 ? (
          <p className="text-gray-500 text-center">No posts yet. Create your first post above!</p>
        ) : (
          posts.map(post => (
            <div
              key={post._id}
              className="bg-white p-6 rounded-2xl shadow-md hover:shadow-lg transition duration-300"
            >
              <h3 className="text-xl font-semibold text-gray-800 mb-2">{post.title}</h3>
              <p className="text-gray-700 mb-3 whitespace-pre-wrap">{post.content}</p>
              <p className="text-sm text-gray-500">
                Posted on {new Date(post.createdAt).toLocaleString()}
              </p>
            </div>
          ))
        )}
      </div>
    </div>
  )
}
