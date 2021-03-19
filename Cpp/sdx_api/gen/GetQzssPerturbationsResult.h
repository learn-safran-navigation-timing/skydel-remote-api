#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetQzssPerturbations
    ///
    /// Name Type   Description
    /// ---- ------ ---------------------
    /// SvId int    Satellite SV ID 1..10
    /// Crs  double Crs (meter)
    /// Crc  double Crc (meter)
    /// Cis  double Crs (rad)
    /// Cic  double Crc (rad)
    /// Cus  double Cus (rad)
    /// Cuc  double Cuc (rad)
    ///

    class GetQzssPerturbationsResult;
    typedef std::shared_ptr<GetQzssPerturbationsResult> GetQzssPerturbationsResultPtr;
    
    
    class GetQzssPerturbationsResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssPerturbationsResult();

      GetQzssPerturbationsResult(CommandBasePtr relatedCommand, int svId, double crs, double crc, double cis, double cic, double cus, double cuc);
  
      static GetQzssPerturbationsResultPtr create(CommandBasePtr relatedCommand, int svId, double crs, double crc, double cis, double cic, double cus, double cuc);
      static GetQzssPerturbationsResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** crs ****
      double crs() const;
      void setCrs(double crs);


      // **** crc ****
      double crc() const;
      void setCrc(double crc);


      // **** cis ****
      double cis() const;
      void setCis(double cis);


      // **** cic ****
      double cic() const;
      void setCic(double cic);


      // **** cus ****
      double cus() const;
      void setCus(double cus);


      // **** cuc ****
      double cuc() const;
      void setCuc(double cuc);
    };
  }
}

