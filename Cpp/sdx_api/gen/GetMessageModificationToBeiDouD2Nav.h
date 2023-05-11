#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get infos about the BeiDou D2 NAV message modification with this ID.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetMessageModificationToBeiDouD2Nav;
    typedef std::shared_ptr<GetMessageModificationToBeiDouD2Nav> GetMessageModificationToBeiDouD2NavPtr;
    
    
    class GetMessageModificationToBeiDouD2Nav : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMessageModificationToBeiDouD2Nav();

      GetMessageModificationToBeiDouD2Nav(const std::string& id);

      static GetMessageModificationToBeiDouD2NavPtr create(const std::string& id);
      static GetMessageModificationToBeiDouD2NavPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

