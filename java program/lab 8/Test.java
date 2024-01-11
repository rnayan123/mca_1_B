import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
 class Test {
    public static void main(String[] args) {
        Property property1 = new Property(1, "Sg palya", 250000, 3, 2);
        Property property2 = new Property(2, "Koramangala", 350000, 4, 3);

        Agent agent1 = new Agent(101, "Suryansh");
        agent1.addProperty(property1);
        agent1.addProperty(property2);

        Agent agent2 = new Agent(102, "Vishal");

        Buyer buyer1 = new Buyer(201, "Anurag", 300000);
        Buyer buyer2 = new Buyer(202, "Subham", 400000);

        RealEstateCollection realEstateCollection = new RealEstateCollection();

        realEstateCollection.addProperty(property1);
        realEstateCollection.addProperty(property2);

        realEstateCollection.addAgent(agent1);
        realEstateCollection.addAgent(agent2);

        realEstateCollection.addBuyer(buyer1);
        realEstateCollection.addBuyer(buyer2);

        System.out.println(realEstateCollection);
    }
}

class Property {
    private int propertyId;
    private String address;
    private double price;
    private int bedrooms;
    private int bathrooms;

    public Property(int propertyId, String address, double price, int bedrooms, int bathrooms) {
        this.propertyId = propertyId;
        this.address = address;
        this.price = price;
        this.bedrooms = bedrooms;
        this.bathrooms = bathrooms;
    }

    @Override
    public String toString() {
        return String.format("Property ID: %d, Address: %s, Price: Rs%.2f, Bedrooms: %d, Bathrooms: %d",
                propertyId, address, price, bedrooms, bathrooms);
    }
}

class Agent {
    private int agentId;
    private String name;
    private List<Property> properties;

    public Agent(int agentId, String name) {
        this.agentId = agentId;
        this.name = name;
        this.properties = new ArrayList<>();
    }

    public int getAgentId() {
        return agentId;
    }

    public void addProperty(Property property) {
        properties.add(property);
    }

    @Override
    public String toString() {
        StringBuilder agentString = new StringBuilder(String.format("Agent ID: %d, Name: %s\n", agentId, name));
        for (Property property : properties) {
            agentString.append("  ").append(property).append("\n");
        }
        return agentString.toString();
    }
}

class Buyer {
    private int buyerId;
    private String name;
    private double budget;

    public Buyer(int buyerId, String name, double budget) {
        this.buyerId = buyerId;
        this.name = name;
        this.budget = budget;
    }

    @Override
    public String toString() {
        return String.format("Buyer ID: %d, Name: %s, Budget: Rs%.2f", buyerId, name, budget);
    }
}

class RealEstateCollection {
    private List<Property> properties;
    private Map<Integer, Agent> agents;
    private Set<Buyer> buyers;

    public RealEstateCollection() {
        this.properties = new ArrayList<>();
        this.agents = new HashMap<>();
        this.buyers = new HashSet<>();
    }

    public void addProperty(Property property) {
        properties.add(property);
    }

    public void addAgent(Agent agent) {
        agents.put(agent.getAgentId(), agent);
    }

    public void addBuyer(Buyer buyer) {
        buyers.add(buyer);
    }

    @Override
    public String toString() {
        StringBuilder collectionString = new StringBuilder("Real Estate Collection:\n");
        collectionString.append("Properties:\n");
        for (Property property : properties) {
            collectionString.append("  ").append(property).append("\n");
        }
        collectionString.append("Agents:\n");
        for (Agent agent : agents.values()) {
            collectionString.append(agent);
        }
        collectionString.append("Buyers:\n");
        for (Buyer buyer : buyers) {
            collectionString.append("  ").append(buyer).append("\n");
        }
        return collectionString.toString();
    }
}

