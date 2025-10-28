const express = require('express')
const Post = require('../models/Post')
const auth = require('../middleware/auth')

const router = express.Router()

// Get all posts
router.get('/', async (req, res) => {
  const posts = await Post.find().populate('author', 'name email').sort({ createdAt: -1 })
  res.json(posts)
})

// Get one post
router.get('/:id', async (req, res) => {
  const post = await Post.findById(req.params.id).populate('author', 'name email')
  res.json(post)
})

// Create post (protected)
router.post('/', auth, async (req, res) => {
  const { title, content } = req.body
  const post = await Post.create({ title, content, author: req.userId })
  res.json(post)
})

// Update post (protected)
router.put('/:id', auth, async (req, res) => {
  const post = await Post.findById(req.params.id)
  if (!post) return res.status(404).json({ message: 'Post not found' })
  if (post.author.toString() !== req.userId) return res.status(403).json({ message: 'Forbidden' })

  post.title = req.body.title || post.title
  post.content = req.body.content || post.content
  post.updatedAt = Date.now()
  await post.save()
  res.json(post)
})

// Delete post (protected)
router.delete('/:id', auth, async (req, res) => {
  const post = await Post.findById(req.params.id)
  if (!post) return res.status(404).json({ message: 'Post not found' })
  if (post.author.toString() !== req.userId) return res.status(403).json({ message: 'Forbidden' })

  await post.deleteOne()
  res.json({ message: 'Post deleted' })
})

module.exports = router
