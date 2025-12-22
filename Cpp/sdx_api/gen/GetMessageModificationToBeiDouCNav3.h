#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get infos about the BeiDou CNAV3 message modification with this ID.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetMessageModificationToBeiDouCNav3;
    typedef std::shared_ptr<GetMessageModificationToBeiDouCNav3> GetMessageModificationToBeiDouCNav3Ptr;
    
    
    class GetMessageModificationToBeiDouCNav3 : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetMessageModificationToBeiDouCNav3();

      GetMessageModificationToBeiDouCNav3(const std::string& id);

      static GetMessageModificationToBeiDouCNav3Ptr create(const std::string& id);
      static GetMessageModificationToBeiDouCNav3Ptr dynamicCast(CommandBasePtr ptr);
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

