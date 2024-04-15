#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Get all OSNMA Merkle Trees unique identifiers.
    ///
    /// 
    ///

    class GetAllMerkleTreeID;
    typedef std::shared_ptr<GetAllMerkleTreeID> GetAllMerkleTreeIDPtr;
    
    
    class GetAllMerkleTreeID : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetAllMerkleTreeID();

      static GetAllMerkleTreeIDPtr create();
      static GetAllMerkleTreeIDPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

