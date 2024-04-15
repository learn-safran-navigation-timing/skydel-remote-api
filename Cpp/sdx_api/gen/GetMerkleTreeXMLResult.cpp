
#include "GetMerkleTreeXMLResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMerkleTreeXMLResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMerkleTreeXMLResult::CmdName = "GetMerkleTreeXMLResult";
    const char* const GetMerkleTreeXMLResult::Documentation = "Result of GetMerkleTreeXML.\n"
      "\n"
      "Name             Type      Description\n"
      "---------------- --------- ---------------------------------------------------------------------------------------------------------------------------\n"
      "Id               string    Merkle Tree unique identifier.\n"
      "PublicKeyIndexes array int Indexes (0-based) of Public Keys to export in the Merkle Tree. If empty, only the Public Key with index 0 will be exported.\n"
      "MerkleTreeXML    string    Merkle Tree XML representation.";
    const char* const GetMerkleTreeXMLResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMerkleTreeXMLResult);


    GetMerkleTreeXMLResult::GetMerkleTreeXMLResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetMerkleTreeXMLResult::GetMerkleTreeXMLResult(const std::string& id, const std::vector<int>& publicKeyIndexes, const std::string& merkleTreeXML)
      : CommandResult(CmdName, TargetId)
    {

      setId(id);
      setPublicKeyIndexes(publicKeyIndexes);
      setMerkleTreeXML(merkleTreeXML);
    }

    GetMerkleTreeXMLResult::GetMerkleTreeXMLResult(CommandBasePtr relatedCommand, const std::string& id, const std::vector<int>& publicKeyIndexes, const std::string& merkleTreeXML)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setId(id);
      setPublicKeyIndexes(publicKeyIndexes);
      setMerkleTreeXML(merkleTreeXML);
    }


    GetMerkleTreeXMLResultPtr GetMerkleTreeXMLResult::create(const std::string& id, const std::vector<int>& publicKeyIndexes, const std::string& merkleTreeXML)
    {
      return std::make_shared<GetMerkleTreeXMLResult>(id, publicKeyIndexes, merkleTreeXML);
    }

    GetMerkleTreeXMLResultPtr GetMerkleTreeXMLResult::create(CommandBasePtr relatedCommand, const std::string& id, const std::vector<int>& publicKeyIndexes, const std::string& merkleTreeXML)
    {
      return std::make_shared<GetMerkleTreeXMLResult>(relatedCommand, id, publicKeyIndexes, merkleTreeXML);
    }

    GetMerkleTreeXMLResultPtr GetMerkleTreeXMLResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMerkleTreeXMLResult>(ptr);
    }

    bool GetMerkleTreeXMLResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<std::vector<int>>::is_valid(m_values["PublicKeyIndexes"])
          && parse_json<std::string>::is_valid(m_values["MerkleTreeXML"])
        ;

    }

    std::string GetMerkleTreeXMLResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMerkleTreeXMLResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id", "PublicKeyIndexes", "MerkleTreeXML"}; 
      return names; 
    }


    std::string GetMerkleTreeXMLResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMerkleTreeXMLResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<int> GetMerkleTreeXMLResult::publicKeyIndexes() const
    {
      return parse_json<std::vector<int>>::parse(m_values["PublicKeyIndexes"]);
    }

    void GetMerkleTreeXMLResult::setPublicKeyIndexes(const std::vector<int>& publicKeyIndexes)
    {
      m_values.AddMember("PublicKeyIndexes", parse_json<std::vector<int>>::format(publicKeyIndexes, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMerkleTreeXMLResult::merkleTreeXML() const
    {
      return parse_json<std::string>::parse(m_values["MerkleTreeXML"]);
    }

    void GetMerkleTreeXMLResult::setMerkleTreeXML(const std::string& merkleTreeXML)
    {
      m_values.AddMember("MerkleTreeXML", parse_json<std::string>::format(merkleTreeXML, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
