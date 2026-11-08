import kagglehub
from kagglehub import KaggleDatasetAdapter

df = kagglehub.load_dataset(
    KaggleDatasetAdapter.PANDAS,
    "maharshipandya/-spotify-tracks-dataset",
    "dataset.csv",
)

df.to_csv("spotify.csv", index=False)
print(df.head())
