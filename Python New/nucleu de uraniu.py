import math

energy = 200000000

def FindParticle(mass, speed):
    if mass >=2 and speed <= 10000:
        return 0
    if mass < 2 and speed >= 15000:
        return 1
    return 2


def CheckIfHits(distance, angle):
    return angle <= (math.atan(153/distance))


def CheckDangerous(speed, mass):
    speed = speed * 1000
    mass = mass / 1000000
    return (mass * speed**2 / 2) >= energy

particleNumber = int(input())
particleList = 3*[0]
particlesThatHit = 3*[0]
dangerousParticles = 3*[0]
hits = 0
dangerous = 0

for i in range(particleNumber):
    particleDetails = list(map(float, input().split()))

    particleList[FindParticle(particleDetails[1], particleDetails[-1])] += 1

    print(f'{math.atan(153/particleDetails[0])} vs {particleDetails[2]} particle type {FindParticle(particleDetails[1], particleDetails[-1])}')

    if CheckIfHits(particleDetails[0], particleDetails[2]):
        hits += 1
        particlesThatHit[FindParticle(particleDetails[1], particleDetails[-1])] += 1

        if CheckDangerous(particleDetails[-1], particleDetails[1]):
            dangerous += 1
            dangerousParticles[FindParticle(particleDetails[1], particleDetails[-1])] += 1

print(f'{hits} {dangerous}')

print(*particleList)
print(*particlesThatHit)
print(*dangerousParticles)