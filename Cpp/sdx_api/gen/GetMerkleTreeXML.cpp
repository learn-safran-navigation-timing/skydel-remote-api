
#include "GetMerkleTreeXML.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMerkleTreeXML
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMerkleTreeXML::CmdName = "GetMerkleTreeXML";
    const char* const GetMerkleTreeXML::Documentation = "Get Get an OSNMA Merkle Tree XML representation with the format defined in the Galileo OSNMA IDD ICD.\n"
      "\n"
      "Name             Type      Description\n"
      "---------------- --------- ---------------------------------------------------------------------------------------------------------------------------\n"
      "Id               string    Merkle Tree unique identifier.\n"
      "PublicKeyIndexes array int Indexes (0-based) of Public Keys to export in the Merkle Tree. If empty, only the Public Key with index 0 will be exported.";
    const char* const GetMerkleTreeXML::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMerkleTreeXML);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMerkleTreeXML);


    GetMerkleTreeXML::GetMerkleTreeXML()
      : CommandBase(CmdName, TargetId)
    {}

    GetMerkleTreeXML::GetMerkleTreeXML(const std::string& id, const std::vector<int>& publicKeyIndexes)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
      setPublicKeyIndexes(publicKeyIndexes);
    }

    GetMerkleTreeXMLPtr GetMerkleTreeXML::create(const std::string& id, const std::vector<int>& publicKeyIndexes)
    {
      return std::make_shared<GetMerkleTreeXML>(id, publicKeyIndexes);
    }

    GetMerkleTreeXMLPtr GetMerkleTreeXML::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMerkleTreeXML>(ptr);
    }

    bool GetMerkleTreeXML::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<std::vector<int>>::is_valid(m_values["PublicKeyIndexes"])
        ;

    }

    std::string GetMerkleTreeXML::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMerkleTreeXML::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id", "PublicKeyIndexes"}; 
      return names; 
    }


    int GetMerkleTreeXML::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMerkleTreeXML::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMerkleTreeXML::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<int> GetMerkleTreeXML::publicKeyIndexes() const
    {
      return parse_json<std::vector<int>>::parse(m_values["PublicKeyIndexes"]);
    }

    void GetMerkleTreeXML::setPublicKeyIndexes(const std::vector<int>& publicKeyIndexes)
    {
      m_values.AddMember("PublicKeyIndexes", parse_json<std::vector<int>>::format(publicKeyIndexes, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
