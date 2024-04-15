
#include "ExportMerkleTree.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ExportMerkleTree
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ExportMerkleTree::CmdName = "ExportMerkleTree";
    const char* const ExportMerkleTree::Documentation = "Export an OSNMA Merkle Tree to an XML file with the format defined in the Galileo OSNMA IDD ICD.\n"
      "\n"
      "Name             Type      Description\n"
      "---------------- --------- ----------------------------------------------------------------------------------------------------------\n"
      "Id               string    Merkle Tree unique identifier.\n"
      "PublicKeyIndexes array int Indexes (0-based) of Public Keys to export in the Merkle Tree. If empty, all Public Keys will be exported.\n"
      "FilePath         string    Export file path for the Merkle Tree.\n"
      "OverwriteFile    bool      When selected, existing file will be overwritten.";
    const char* const ExportMerkleTree::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ExportMerkleTree);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ExportMerkleTree);


    ExportMerkleTree::ExportMerkleTree()
      : CommandBase(CmdName, TargetId)
    {}

    ExportMerkleTree::ExportMerkleTree(const std::string& id, const std::vector<int>& publicKeyIndexes, const std::string& filePath, bool overwriteFile)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
      setPublicKeyIndexes(publicKeyIndexes);
      setFilePath(filePath);
      setOverwriteFile(overwriteFile);
    }

    ExportMerkleTreePtr ExportMerkleTree::create(const std::string& id, const std::vector<int>& publicKeyIndexes, const std::string& filePath, bool overwriteFile)
    {
      return std::make_shared<ExportMerkleTree>(id, publicKeyIndexes, filePath, overwriteFile);
    }

    ExportMerkleTreePtr ExportMerkleTree::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ExportMerkleTree>(ptr);
    }

    bool ExportMerkleTree::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<std::vector<int>>::is_valid(m_values["PublicKeyIndexes"])
          && parse_json<std::string>::is_valid(m_values["FilePath"])
          && parse_json<bool>::is_valid(m_values["OverwriteFile"])
        ;

    }

    std::string ExportMerkleTree::documentation() const { return Documentation; }

    const std::vector<std::string>& ExportMerkleTree::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id", "PublicKeyIndexes", "FilePath", "OverwriteFile"}; 
      return names; 
    }


    int ExportMerkleTree::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ExportMerkleTree::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void ExportMerkleTree::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<int> ExportMerkleTree::publicKeyIndexes() const
    {
      return parse_json<std::vector<int>>::parse(m_values["PublicKeyIndexes"]);
    }

    void ExportMerkleTree::setPublicKeyIndexes(const std::vector<int>& publicKeyIndexes)
    {
      m_values.AddMember("PublicKeyIndexes", parse_json<std::vector<int>>::format(publicKeyIndexes, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ExportMerkleTree::filePath() const
    {
      return parse_json<std::string>::parse(m_values["FilePath"]);
    }

    void ExportMerkleTree::setFilePath(const std::string& filePath)
    {
      m_values.AddMember("FilePath", parse_json<std::string>::format(filePath, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool ExportMerkleTree::overwriteFile() const
    {
      return parse_json<bool>::parse(m_values["OverwriteFile"]);
    }

    void ExportMerkleTree::setOverwriteFile(bool overwriteFile)
    {
      m_values.AddMember("OverwriteFile", parse_json<bool>::format(overwriteFile, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
