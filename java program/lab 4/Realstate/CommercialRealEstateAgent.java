package Realstate;

public class CommercialRealEstateAgent implements RealEstateAgent {
    @Override
    public void promoteListing(RealEstateListing listing) {
        System.out.println("Commercial Property Promotion");
    }

    @Override
    public void sellProperty(RealEstateListing listing) {
        System.out.println("Commercial Property Sold");
    }

}
