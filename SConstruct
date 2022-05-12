DIR = 'basics'
env = Environment()
env.Append(CCFLAGS='-Wall -Wextra  -std=c11')

for item in Glob('basics/*.c'):
    env.Program(item)
