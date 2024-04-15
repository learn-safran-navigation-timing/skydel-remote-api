#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Remove an OSNMA Merkle Tree.
    ///
    /// Name Type   Description
    /// ---- ------ -----------------------------------------------
    /// Id   string Unique identifier of the Merkle Tree to remove.
    ///

    class RemoveMerkleTree;
    typedef std::shared_ptr<RemoveMerkleTree> RemoveMerkleTreePtr;
    
    
    class RemoveMerkleTree : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      RemoveMerkleTree();

      RemoveMerkleTree(const std::string& id);

      static RemoveMerkleTreePtr create(const std::string& id);
      static RemoveMerkleTreePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

