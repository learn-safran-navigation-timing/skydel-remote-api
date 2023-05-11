#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get infos about the BeiDou CNAV1 message modification with this ID.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetMessageModificationToBeiDouCNav1;
    typedef std::shared_ptr<GetMessageModificationToBeiDouCNav1> GetMessageModificationToBeiDouCNav1Ptr;
    
    
    class GetMessageModificationToBeiDouCNav1 : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMessageModificationToBeiDouCNav1();

      GetMessageModificationToBeiDouCNav1(const std::string& id);

      static GetMessageModificationToBeiDouCNav1Ptr create(const std::string& id);
      static GetMessageModificationToBeiDouCNav1Ptr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

