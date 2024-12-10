import media_tools

def main():
    img = media_tools.Image(1024, 768)

    img.open("Lenna.png")

    img.inverse()
    img.save("Lenna_inv.png")

    img.flip()
    img.save("Lenna_inv_flip.png")

if __name__ == "__main__":
    main()