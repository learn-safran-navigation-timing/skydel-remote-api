#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the service provider of all the SBAS satellites.
    ///
    /// 
    ///

    class GetSbasServiceProviderForEachSV;
    typedef std::shared_ptr<GetSbasServiceProviderForEachSV> GetSbasServiceProviderForEachSVPtr;
    
    
    class GetSbasServiceProviderForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSbasServiceProviderForEachSV();

      static GetSbasServiceProviderForEachSVPtr create();
      static GetSbasServiceProviderForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

