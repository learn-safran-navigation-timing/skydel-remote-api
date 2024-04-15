#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get infos about the QZSS SLAS message modification with this ID.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetMessageModificationToQzssSlas;
    typedef std::shared_ptr<GetMessageModificationToQzssSlas> GetMessageModificationToQzssSlasPtr;
    
    
    class GetMessageModificationToQzssSlas : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetMessageModificationToQzssSlas();

      GetMessageModificationToQzssSlas(const std::string& id);

      static GetMessageModificationToQzssSlasPtr create(const std::string& id);
      static GetMessageModificationToQzssSlasPtr dynamicCast(CommandBasePtr ptr);
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

