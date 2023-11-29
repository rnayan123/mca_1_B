package Realstate;

public class ResidentialRealEstateAgent implements RealEstateAgent {

    @Override
    public void promoteListing(RealEstateListing listing) {
        System.out.println("Residential Property Promotion");
    }

    @Override
    public void sellProperty(RealEstateListing listing) {
        System.out.println("Residential Property Sold");
    }
    
}
