#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get infos about the BeiDou D1 NAV message modification with this ID.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetMessageModificationToBeiDouD1Nav;
    typedef std::shared_ptr<GetMessageModificationToBeiDouD1Nav> GetMessageModificationToBeiDouD1NavPtr;
    
    
    class GetMessageModificationToBeiDouD1Nav : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetMessageModificationToBeiDouD1Nav();

      GetMessageModificationToBeiDouD1Nav(const std::string& id);

      static GetMessageModificationToBeiDouD1NavPtr create(const std::string& id);
      static GetMessageModificationToBeiDouD1NavPtr dynamicCast(CommandBasePtr ptr);
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

